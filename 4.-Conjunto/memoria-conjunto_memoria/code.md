```cpp
string CSMemoria::obtener_id(string cadena, int n) {
    // a,b,c,d
    // ,,,a,b,c,d,,,
    // a,,,b,,,c,,,d
    string id = "";
    bool b = false;
    int c = 0;
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] != ',') {
            if (!b)
                c++;

            if (c == n)
                id += cadena[i];
            b = true;

        } else {
            if (b && c == n) {
                return id;
            }
            b = false;
        }
    }
    return id;
}
```

```cpp
// elimina la flecha
string CSMemoria::eliminar_flecha(string cadena) {
    int pos = 0;
    if (cadena.empty())
        return "";
    while (cadena[pos] != '-' && cadena[pos + 1] != '>') {
        pos++;
    }
    return cadena.substr(pos + 2, cadena.length() - cadena.substr(0, pos + 1).length());
}
```