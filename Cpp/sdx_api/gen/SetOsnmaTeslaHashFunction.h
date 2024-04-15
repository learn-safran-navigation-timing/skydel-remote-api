#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA TESLA hash function.
    ///
    /// Name         Type   Description
    /// ------------ ------ -------------------------------------------------------------------------------------
    /// HashFunction string Hash function used for the TESLA chain. Hash functions are: "SHA-256" and "SHA3-256".
    ///

    class SetOsnmaTeslaHashFunction;
    typedef std::shared_ptr<SetOsnmaTeslaHashFunction> SetOsnmaTeslaHashFunctionPtr;
    
    
    class SetOsnmaTeslaHashFunction : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetOsnmaTeslaHashFunction();

      SetOsnmaTeslaHashFunction(const std::string& hashFunction);

      static SetOsnmaTeslaHashFunctionPtr create(const std::string& hashFunction);
      static SetOsnmaTeslaHashFunctionPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** hashFunction ****
      std::string hashFunction() const;
      void setHashFunction(const std::string& hashFunction);
    };
    
  }
}

