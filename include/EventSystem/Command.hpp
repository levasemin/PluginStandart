#pragma once

namespace booba
{
    template<class ...Tparams>
    class Command
    {
    public:
        virtual ~Command() = default; 

        virtual void Execute(Tparams... params) = 0;
    };
}