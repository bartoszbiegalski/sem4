using System;

namespace GFNamespace {
	public class Program {
		public static void Main() {
			GF first = new GF(13, 8);
			GF second = new GF(13, 2);

			Console.WriteLine(first + " " + second);

			first+=second;

			Console.WriteLine(first+second);

			first = second;

			Console.WriteLine(first + " " + second);

			Console.WriteLine(first-second);

			Console.WriteLine(first*second);

			Console.WriteLine(first/second);


		}
	}
}
