xsdcxx cxx-tree --generate-doxygen --generate-ostream --hxx-suffix .h --cxx-suffix .cpp --root-element-first --generate-polymorphic --generate-serialization --output-dir ../include/mesh mesh_h2d_xml.xsd
xsdcxx cxx-tree --generate-doxygen --generate-ostream --hxx-suffix .h --cxx-suffix .cpp --generate-serialization --output-dir ../include/mesh subdomains_h2d_xml.xsd
mv -f ../include/mesh/*.cpp ../src/mesh
