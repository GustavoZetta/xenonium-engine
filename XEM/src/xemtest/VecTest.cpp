#include <xem/XEM.hpp>

#include <xemtest/XEMTEST.hpp>

#include <iostream>

namespace xem {
	bool VecTest() {
		try {
			for (size_t i = 0; i < 6; i++) {
				std::cout << " ############### Vec " << i << " ###############" << std::endl;
				Vec<3, float> v(static_cast<float>(i));

				// Vec struct functions
				std::cout << "Components: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;
				std::cout << "Squared Length: " << v.SquaredLength() << std::endl;
				std::cout << "Length: " << v.Length() << std::endl;

				// Vec Math functions
				Vec<3, float> normalized = xem::Normalize(v);
				std::cout << "Normalized: x " << normalized.X() << " y " << normalized.Y() << " z " << normalized.Z() << std::endl;

				// Vec for operations
				Vec<3, float> constantVec(10.0f, 0.0f, 2.0f);
				std::cout << "Constant Vec: x " << constantVec.X() << " y " << constantVec.Y() << " z " << constantVec.Z() << std::endl;

				// Vector Arithmetic Operators
				std::cout << "-------- Vec Arithmetic Operators --------" << std::endl;
				std::cout << "Addition: Vec " << i << " + Constant Vec" << std::endl;
				Vec<3, float> result = v + constantVec;
				std::cout << "Result: x " << result.X() << " y " << result.Y() << " z " << result.Z() << std::endl;

				std::cout << "Subtraction: Vec " << i << " - Constant Vec" << std::endl;
				result = v - constantVec;
				std::cout << "Result: x " << result.X() << " y " << result.Y() << " z " << result.Z() << std::endl;

				// Scalars Arithmetic Operators
				std::cout << "-------- Scalars Arithmetic Operators --------" << std::endl;
				std::cout << "Addition: Vec " << i << " + 4.0f" << std::endl;
				result = v + 4.0f;
				std::cout << "Result: x " << result.X() << " y " << result.Y() << " z " << result.Z() << std::endl;

				std::cout << "Subtraction: Vec " << i << " - 4.0f" << std::endl;
				result = v - 4.0f;
				std::cout << "Result: x " << result.X() << " y " << result.Y() << " z " << result.Z() << std::endl;

				std::cout << "Division: Vec " << i << " / 4.0f" << std::endl;
				result = v / 4.0f;
				std::cout << "Result: x " << result.X() << " y " << result.Y() << " z " << result.Z() << std::endl;

				std::cout << "Multiplication: Vec " << i << " * 4.0f" << std::endl;
				result = v * 4.0f;
				std::cout << "Result: x " << result.X() << " y " << result.Y() << " z " << result.Z() << std::endl;

				// Vec Arithmetic Assignment Operators
				std::cout << "-------- Vec Arithmetic Assignment Operators --------" << std::endl;
				std::cout << "Initial Value: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;
				std::cout << "Addition: Vec " << i << " += Vec<3, float>(1.0f, 3.0f, 2.0f)" << std::endl;
				v += Vec<3, float>(1.0f, 3.0f, 2.0f);
				std::cout << "Result: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;

				std::cout << "Subtraction: Vec " << i << " -= Vec<3, float>(10.0f, -2.0f, 5.0f)" << std::endl;
				v -= Vec<3, float>(10.0f, -2.0f, 5.0f);
				std::cout << "Result: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;
				std::cout << "Final Value: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;

				// Scalars Arithmetic Assignment Operators
				std::cout << "-------- Scalars Arithmetic Assignment Operators --------" << std::endl;
				std::cout << "Initial Value: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;
				std::cout << "Addition: Vec " << i << " += 4.0f" << std::endl;
				v += 4.0f;
				std::cout << "Result: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;

				std::cout << "Subtraction: Vec " << i << " -= 6.0f" << std::endl;
				v -= 6.0f;
				std::cout << "Result: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;

				std::cout << "Multiplication: Vec " << i << " *= 2.0f" << std::endl;
				v *= 2.0f;
				std::cout << "Result: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;

				std::cout << "Division: Vec " << i << " /= 1.5f" << std::endl;
				v /= 1.5f;
				std::cout << "Result: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;
				std::cout << "Final Value: x " << v.X() << " y " << v.Y() << " z " << v.Z() << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cerr << "Found an exception when executing xem::VecTest()" << "\n";
			std::cerr << e.what() << "\n";
			return false;
		}

		return true;
	}
}
