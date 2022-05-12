# Program Structure

Good software engineering is creating large programs from smaller components

- Coupling and cohesion
  - cohesion is act of commonality of different code components. how releated functions, objects are related to each other
  - coupluing is intedependency in interfaces. 
- Code reuse
  - dont repeat yourself. write one piece of correct code once and reuse it as needed
- Data Abstractions
  - reusable code components that enforces clear sepereation between interface and implementation
  - heave headers include required headers and have self contained headers that do not depend on anything else
  - source files implement interface defined by header files
- opaque types
  - private data types hide implementation in order to keep users from overdepending on internal implementation
  - changes in implementation should not change behaviour on correct usage
- executables
  - compiler changes source into object code, then links into final executable
  - linking allows for easy reuse and recompile of code without recompiling everything
  - libraries allows to build on previous or seperate work in order to focus on unique logic of program
- `static library`: code incoporated into resulting binary
- `dynamic library`: code that is seperately loaded and must exist somewhere where it can be found in order to be used. can be shared with other programs
- linkage
  - controls private and public interfaces and finds duplicates
  - translation units at the file lavel are implicitly considered externally linked. global variables
