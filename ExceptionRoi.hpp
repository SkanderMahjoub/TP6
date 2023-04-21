#pragma once
#include <stdexcept>
#include <string>


class KingException : public std::exception{
public:

	KingException(const std::string& message) : m_message(message){
		throw KingException("Il y a plus que deux rois.");
	}


private:
	std::string m_message;
};
