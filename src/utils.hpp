#ifndef UTILS_HPP
#define UTILS_HPP
#include <map>
#include <string>

typedef std::map<std::string, double> VarMap;

static double getVar(const std::string& name, VarMap& vars) {
    if (vars.find(name) != vars.end()) return vars[name];
    return 0;
}

static void setVar(const std::string& name, double val, VarMap& vars) {
    vars[name] = val;
}
#endif
