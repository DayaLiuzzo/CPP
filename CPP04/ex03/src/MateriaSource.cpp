#include "MateriaSource.hpp"

// constructors
MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for(int i = 0; i < 4; i++)
    {
        if(other._materias[i])
        {
            _materias[i] = other._materias[i]->clone();
            _materias[i]->setMateriaSource(this);
        }
        else
            _materias[i] = NULL;
        _materias[i] = other._materias[i];
    }
}

//destructor
MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if (this->_materias[i])
            delete this->_materias[i];
    }
}
//operators
MateriaSource &MateriaSource::operator=(MateriaSource other)
{
    MateriaSource::swap(*this, other);
    return *this;
}

void MateriaSource::swap(MateriaSource &first, MateriaSource &second) {
  std::swap(first._materias, second._materias);
}

//member functions
void MateriaSource::learnMateria(AMateria *materia)
{
    for(int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = materia;
            std::cout << "Materia source learned" << std::endl;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
