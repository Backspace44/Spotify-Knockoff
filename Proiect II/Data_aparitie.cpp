//Data_aparitie.cpp
#include "Data_aparitie.h"

Data_aparitie::Data_aparitie()
        :_zi(0),
        _luna(""),
        _an(0)
    { }
Data_aparitie::Data_aparitie(int zi, std::string luna, int an)
        : _zi(zi),
        _luna(luna),
        _an(an)
    { }
Data_aparitie::Data_aparitie(const Data_aparitie& obj)
        : _zi(obj._zi),
        _luna(obj._luna),
        _an(obj._an)
{}
    bool Data_aparitie::operator==(const Data_aparitie& d) {
        return _zi == d._zi && _luna == d._luna && _an == d._an;
    }