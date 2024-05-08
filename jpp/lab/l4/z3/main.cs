using System;

namespace GFNamespace {
    public class Program {
        public static void Main() {
					GF first = new GF(31, 8);
          first.is_generator(new GF(31, 3));
		      DHSetup<GF> dhSetup = new DHSetup<GF>(first);

				  User<DHSetup<GF>, GF> A = new User<DHSetup<GF>, GF>(dhSetup);

          Console.WriteLine(first. ToString());

					User<DHSetup<GF>, GF> B = new User<DHSetup<GF>, GF>(dhSetup);

          GF message = new GF(31, 9);

        }
    }
}
