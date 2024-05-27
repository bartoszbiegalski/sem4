from igraph import Graph, plot
import random
import generate_matrix

# G = Graph()

# # Open the nodes file
# with open('nodes.txt', 'r') as f:
#     # Read the lines into a list
#     nodes = f.readlines()

# # Remove any newline characters
# nodes = [node.strip() for node in nodes]

# # Add the nodes to the graph
# G.add_vertices(nodes)

# # Open the edges file
# with open('edges.txt', 'r') as f:
#     # Read the lines into a list
#     lines = f.readlines()

# # Remove any newline characters and split each line into a pair of nodes and a capacity
# edges = [(line.strip().split()[0], line.strip().split()[1]) for line in lines]
# capacities = [int(line.strip().split()[2]) for line in lines]
# reliabilities = [float(line.strip().split()[3]) for line in lines]

# # Add the edges to the graph
# G.add_edges(edges)

# # Add capacities to the edges
# G.es["capacity"] = capacities
# G.es["reliability"] = reliabilities

# # Generate a layout for the graph
# layout = G.layout("kk")

# # Label the vertices with their names
# for v in G.vs:
#     v["label"] = v["name"]

# # Plot the graph and save it as graph.png
# plot(G, "graph.png", layout=layout)

# edge_id = G.get_eid("Warszawa", "Lublin")
# capacity = G.es[edge_id]["capacity"]
# p = G.es[edge_id]["reliability"]
# print(capacity)
# print(p)

def make_experiment():
    rng = random.Random()

    N = 100000
    avg_packet = 12000

    passed_ex = 0

    G = Graph()

    with open('nodes.txt', 'r') as f:
        nodes = f.readlines()

    nodes = [node.strip() for node in nodes]

    G.add_vertices(nodes)

    with open('edges.txt', 'r') as f:
        lines = f.readlines()

    edges = [(line.strip().split()[0], line.strip().split()[1]) for line in lines]
    capacities = [int(line.strip().split()[2]) for line in lines]
    reliabilities = [float(line.strip().split()[3]) for line in lines]

    G.add_edges(edges)

    G.es["capacity"] = capacities
    G.es["reliability"] = reliabilities

    traffic_matrix = generate_matrix.generate_traffic_matrix()

    for i in range(N):
        print(i)
        A = G.copy()

        for edge in A.es:
            rand_numb = rng.random()
            
            if rand_numb > edge["reliability"]:
                A.es[edge.index].delete()
    
        if not A.is_connected():
            continue

        flows = {edge.index: 0 for edge in A.es}

        flag = False

        for source in A.vs:
            for target in A.vs:
                if source != target:
                    path = A.get_shortest_paths(source, target)[0]

                    for j in range(len(path) - 1):
                        edge_id = A.get_eid(path[j], path[j + 1])
                        flows[edge_id] += traffic_matrix[source["name"]][target["name"]]

        for edge in A.es:
            if flows[edge.index]  * avg_packet > edge["capacity"]:
                flag = True
                break

        if flag:
            continue

        #S = sum(len(values) for values in traffic_matrix.values())
        S = 0

        for city1 in traffic_matrix:
            for city2 in traffic_matrix[city1]:
                S += traffic_matrix[city1][city2]

        X = 0

        for edge in A.es:
            X += flows[edge.index] / ((edge["capacity"] /avg_packet - flows[edge.index]))

        T = 1/S * X

        if T > 0.040:
            continue

        passed_ex += 1

    print(passed_ex/N)

def main():
    make_experiment()

if __name__ == "__main__":
    main()
