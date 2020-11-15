class GeometricObject{

    int id;

public:

    GeometricObject(int iId) : id(iId) {}

    virtual float getArea() {};

    float getId() {return id;} 

};