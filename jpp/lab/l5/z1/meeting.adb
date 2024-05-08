with Ada.Text_IO; use Ada.Text_IO;

procedure fivePhilosophers is
	protected Buffer is 
		entry P;
		entry V;
		function getState return Integer;
	private
		state : Integer := 1;
	end Buffer;
	
	protected body Buffer is
		function getState return Integer is
		begin
			return State;
		end getState;
	
		entry P is
		begin
			state := state - 1;
		end P;
		
		entry V is 
		begin 
			state := state + 1;
		end V;
	end Buffer;

		
	
	task type Philosopher is
		entry initialize (i : Integer);
	end Philosopher;
	
	task body Philosopher is 
		Id : Integer;
	begin 
		accept initialize (i : Integer) do
			Id := i;
		end initalize;
		
		loop
		
		
	end Producer;
begin
	null;
end fivePhilosophers;

