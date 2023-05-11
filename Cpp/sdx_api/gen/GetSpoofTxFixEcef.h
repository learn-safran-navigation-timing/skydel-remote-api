#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get spoofer transmitter static position and orientation
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxFixEcef;
    typedef std::shared_ptr<GetSpoofTxFixEcef> GetSpoofTxFixEcefPtr;
    
    
    class GetSpoofTxFixEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxFixEcef();

      GetSpoofTxFixEcef(const std::string& id);

      static GetSpoofTxFixEcefPtr create(const std::string& id);
      static GetSpoofTxFixEcefPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

