
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_security_x509_ext_PolicyMappings__
#define __gnu_java_security_x509_ext_PolicyMappings__

#pragma interface

#include <gnu/java/security/x509/ext/Extension$Value.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace security
      {
          class OID;
        namespace x509
        {
          namespace ext
          {
              class PolicyMappings;
          }
        }
      }
    }
  }
}

class gnu::java::security::x509::ext::PolicyMappings : public ::gnu::java::security::x509::ext::Extension$Value
{

public:
  PolicyMappings(JArray< jbyte > *);
  virtual ::gnu::java::security::OID * getSubjectDomainPolicy(::gnu::java::security::OID *);
  virtual ::java::lang::String * toString();
  static ::gnu::java::security::OID * ID;
private:
  ::java::util::Map * __attribute__((aligned(__alignof__( ::gnu::java::security::x509::ext::Extension$Value)))) mappings;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_security_x509_ext_PolicyMappings__