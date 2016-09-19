**GXT**
---
gxt is a range of related projects mainly written in c for use on Linux but designed with portability in mind.  
The gxt name derives from a system called fws (in a hal -> ibm or vms -> wnt kind of way!). I worked on fws for many years but sadly its dependence on openVMS hindered its evolution.  
  
For more on gxt see www.benningtons.net  
  
**GXT library projects**
---
Each themed project provides an object library containing functions used by other gxt projects. Although they could also be incorporated into your own project, either as a whole library or as individual code examples.  
As well as the usual purpose of a function (to re-use code) they are also intended to keep system calls or other non-portable code together in one place. Portability issues can then be addressed (i.e. with compiler flags) within these libraries rather than across an entire project.  
In some cases functions are desgned for use from other languages (e.g. Fortran) to enable access to the wealth of system functionality available to c.  
Please note: In most cases there are well-established and much better functions available in the extended c library. I'm not trying to re-invent the wheel or compete with those versions, I'm merely developing my own as a means of learning to code within Linux.  
  
**libgxtut**
---
This project contains a diverse collection of general purpose utility functions that don't (currently) warrant their own project/library.  
Functions are added/improved as and when I need them in other gxt projects. Currently these are:-  

- ut_date --- a collection of date and time handling functions.
- ut_error --- a collection of useful error handling and debugging functions.  


