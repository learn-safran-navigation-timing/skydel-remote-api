#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set wether the transmitter should keep the modifications done during the simulation.
    ///
    /// Name        Type   Description
    /// ----------- ------ ------------------------------------------------------
    /// Persistence bool   True to keep the modifications, false to discard them.
    /// Id          string Transmitter unique identifier.
    ///

    class SetIntTxPersistence;
    typedef std::shared_ptr<SetIntTxPersistence> SetIntTxPersistencePtr;
    
    
    class SetIntTxPersistence : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxPersistence();

      SetIntTxPersistence(bool persistence, const std::string& id);

      static SetIntTxPersistencePtr create(bool persistence, const std::string& id);
      static SetIntTxPersistencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** persistence ****
      bool persistence() const;
      void setPersistence(bool persistence);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

