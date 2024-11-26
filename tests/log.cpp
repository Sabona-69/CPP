#include <iostream>

#define PRINT(x) std::cout << x;

class Log
{
	public:
		int	_Error = 0;
		int	_Warning = 1;
		int	_Info  = 2;

	private:
		int	m_LogLevel = _Info;

	public:
		void Error(std::string message){ 
			if (m_LogLevel >= _Error)
				std :: cout <<  "[ERROR]: " << message << std::endl;
		}
		void Warn(std::string message){
			if (m_LogLevel >= _Warning)
				std :: cout <<  "[WARNING]: " << message << std::endl;
		}
		void Info(std::string message){
			if (m_LogLevel >= _Info)
				std :: cout <<  "[INFO]: " << message << std::endl;
		}
		void	SetLevel(int level){
			m_LogLevel = level;
		}
};


int main()
{
	Log log;
	// log.SetLevel(log._Warning);
	log.Error("alo");
	log.Warn("alo");
	log.Info("alo");
}