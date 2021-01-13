#ifndef ALLEGRO5EXCEPTION_HPP_INCLUDED
#define ALLEGRO5EXCEPTION_HPP_INCLUDED

//Avoid runtime error

#include<stdexcept>
#include<string>

namespace Engine{
    class Allegro5Exception final : public std::runtime_error{
    public:
        //Throw error
        explicit Allegro5Exception(char const* const message) noexcept;
        explicit Allegro5Exception(const std::string& message) noexcept;
    };
}

#endif // ALLEGRO5EXCEPTION_HPP_INCLUDED
