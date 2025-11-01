#include "sys.hpp"
#include <sstream>
#include <vector>

namespace render {
    namespace mesh {
        void loadObject(Object* obj, std::string path) {
            std::vector<std::string> lines;

            std::ifstream in(path);
            std::string line;

            while(std::getline(in, line)) {
                lines.push_back(line);
            }

            std::for_each(lines.begin(), lines.end(), [&](std::string& line) {
                std::stringstream ss(line);

                std::string cmd;

                ss >> cmd;

                if(cmd == "v") {
                    glm::vec3 v;
                    ss >> v.x;
                    ss >> v.y;
                    ss >> v.z;
                    obj->vertices.push_back(v);
                } else if(cmd == "vn") {
                    glm::vec3 n;
                    ss >> n.x;
                    ss >> n.y;
                    ss >> n.z;
                    obj->normals.push_back(n);

                } else if(cmd == "vt") {
                    glm::vec2 tc;
                    ss >> tc.x;
                    ss >> tc.y;
                    tc.y = 1.0 - tc.y;
                    obj->texCoords.push_back(tc);

                } else if(cmd == "f") {
                    std::vector<std::string> faces;
                    faces.resize(3);

                    ss >> faces[0];
                    ss >> faces[1];
                    ss >> faces[2];

                    std::vector<Index> indencies;
                    indencies.resize(3);

                    for(int i = 0; i < faces.size(); i++) {
                        std::stringstream f(faces[i]);
                        std::string fs;
                        std::vector<uint32_t> index;
                        while(std::getline(f, fs, '/')) {
                            index.push_back(std::stoi(fs));
                        }

                        indencies[i].vertice = index[0] - 1;
                        indencies[i].normal = index[2] - 1;
                        indencies[i].texCoord = index[1] - 1;
                    }

                    Face face;
                    face.t1 = indencies[0];
                    face.t2 = indencies[1];
                    face.t3 = indencies[2];

                    obj->faces.push_back(face);
                }
            });
        }



        void Mesh::init(std::string path) {
            Object temp;
            loadObject(&temp, path);

            int index = 0;

            this->vertices.init();
            this->texCoords.init();
            this->indencies.init();

            this->vertices.clear();
            this->texCoords.clear();
            this->indencies.clear();

            for(int i = 0; i < temp.faces.size(); i++) {
                Face f = temp.faces.at(i);
                // 0
                vertices.add3(temp.vertices[f.t1.vertice]);
                texCoords.add2(temp.texCoords[f.t1.texCoord]);
                indencies.add1(index);
                index += 1;
                // 1
                vertices.add3(temp.vertices[f.t2.vertice]);
                texCoords.add2(temp.texCoords[f.t2.texCoord]);
                indencies.add1(index);
                index += 1;
                // 2
                vertices.add3(temp.vertices[f.t3.vertice]);
                texCoords.add2(temp.texCoords[f.t3.texCoord]);
                indencies.add1(index);
                index += 1;
            }

            this->vertices.update();
            this->texCoords.update();
            this->indencies.update();

        }

        void Mesh::release() {
            this->indencies.release();
            this->texCoords.release();
            this->vertices.release();
        }

    }
}