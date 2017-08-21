struct CatClass {
   CatClass(const char* s);
   void meow();
};

void pet(CatClass* m);

void test() {
   unique_ptr<CatClass> ruben(new CatClass("obj1"));

   // can use -> (and *) on the unique_ptr just like with a normal pointer
   ruben->meow(); 

   // to get a plain pointer from the unique_ptr, we use the get() method
   pet(ruben.get()); 

   // use std::move to transfer ownership to india - ruben now holds no pointer
   unique_ptr<CatClass> india(std::move(ruben));

   // assign a new pointer to ruben
   ruben.reset(new CatClass("obj2"));

   // assign a new pointer to india - "obj1" will now automatically be deleted
   india.reset("obj3");

   // set ruben to contain nothing - "obj2" will now automatically be deleted
   ruben.reset();

   // "obj3" will automatically deleted at the end of this function, as india goes out of scope
}
