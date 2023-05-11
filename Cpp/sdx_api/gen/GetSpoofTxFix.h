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

    class GetSpoofTxFix;
    typedef std::shared_ptr<GetSpoofTxFix> GetSpoofTxFixPtr;
    
    
    class GetSpoofTxFix : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxFix();

      GetSpoofTxFix(const std::string& id);

      static GetSpoofTxFixPtr create(const std::string& id);
      static GetSpoofTxFixPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

