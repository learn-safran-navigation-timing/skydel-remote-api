#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the transmitter should keep the modifications done during the simulation.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxPersistence;
    typedef std::shared_ptr<GetIntTxPersistence> GetIntTxPersistencePtr;
    
    
    class GetIntTxPersistence : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxPersistence();

      GetIntTxPersistence(const std::string& id);

      static GetIntTxPersistencePtr create(const std::string& id);
      static GetIntTxPersistencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

