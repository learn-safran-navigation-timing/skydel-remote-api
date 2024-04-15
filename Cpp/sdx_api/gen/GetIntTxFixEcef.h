#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get interference transmitter static position and orientation
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxFixEcef;
    typedef std::shared_ptr<GetIntTxFixEcef> GetIntTxFixEcefPtr;
    
    
    class GetIntTxFixEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxFixEcef();

      GetIntTxFixEcef(const std::string& id);

      static GetIntTxFixEcefPtr create(const std::string& id);
      static GetIntTxFixEcefPtr dynamicCast(CommandBasePtr ptr);
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

