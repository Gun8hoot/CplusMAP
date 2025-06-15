<h1 style="text-align: center">CPlusMap</h1>
<div style="text-align: center" rel="Badge div"> 
    <a href="?"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=white"></a>
    <a href="?"><img src="https://img.shields.io/badge/markdown-%23000000.svg?style=for-the-badge&logo=markdown&logoColor=white"></a>
    <a href="https://github.com/Gun8hoot?tab=repositories&q&type&language=c%2B%2B&sort"><img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"></a>
</div>

<h4>Just a simple port scanner who scan every port from 1 to 65535</h4> 

<h3>📖 • TODO</h3>

---

- [ ] Complete rewrite
- [ ] Do an output system
- [ ] Some optimization to gain speed
- [X] Code the IPv4 check function
- [ ] Code a stealth TCP 
- [ ] Show the service usually associates to the open port
- [X] Create a make file
- [ ] Code a "-T" to reduce speed 
- [ ] Compatibility with windows
- [ ] Error message function 

<br>

<h3>👣 • STEPS : </h3>

---
* __Clone the repository__
```sh
git clone https://github.com/Gun8hoot/CplusMAP
```
* __Go in the repository__
```sh
cd ./CPlusmap
```
* __Use make to compile the program__
```
make
```
* __Execute the program__
```sh
./cplusmap.bin -i {IPv4_ADDRESS}
```

<br>

<h3>🖥️ • BENCHMARK & OPTIMIZATION HISTORY</h3>

---
* ***15/06/2025 (Non-stealth mode)*** :
    * Time to **make** = 1.92s
    * Time to **finish** = 20.26s // Scan every port