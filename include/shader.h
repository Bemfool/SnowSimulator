#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
	/* Function: constructor
	 * Usage: Shader shader1("path/to/vertex/shader", "path/to/fragment/shader");
			  Shader shader2;
			  shader2.init("path/to/vertex/shader", "path/to/fragment/shader");
	 ****************************************************************************
	 * Initialize shader with two files as input.
	 */
	Shader() { }
	Shader(const std::string vertexPath, const std::string fragmentPath);
	void init(const std::string vertexPath, const std::string fragmentPath);

	/* Function: use
	 * Usage: shader.use();
	 ****************************************************************************
	 * Activate shadering program.
	 */
	void use();

	const unsigned int getId() const { return id; }

private:
	unsigned int id;	/* handle */
};
