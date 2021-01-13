#ifndef LOG_HPP_INCLUDED
#define LOG_HPP_INCLUDED

#include <fstream>
#include <iostream>
namespace Engine{
    enum LogType{
        VERBOSE,
        DEBUGGING,
        INFO,
        WARN,
        ERROR
    };
    class LOG final{
        private:
            static bool Enabled;
            static bool LogVerbose;
            static const char* FilePath;
            static const char* getLabel(LogType type);
            std::ofstream ofs;
            bool enabled;
            bool canLog() const;
        public:
            LogType type;
            explicit LOG(LogType type = DEBUGGING);
            ~LOG();
            template<class T>
            LOG& operator<<(const T &msg){
                if(canLog()){
                    std::cout<<msg;
                    ofs<<msg;
                }
                return *this;
            }
            static void SetConfig(bool enabled = false, bool logVerbose = false, const char* filePath = "log.txt");
        };
}

#endif // LOG_HPP_INCLUDED
