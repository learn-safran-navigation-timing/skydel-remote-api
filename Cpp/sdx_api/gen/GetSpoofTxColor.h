#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a spoofer color in spectrums
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxColor;
    typedef std::shared_ptr<GetSpoofTxColor> GetSpoofTxColorPtr;
    
    
    class GetSpoofTxColor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofTxColor();

      GetSpoofTxColor(const std::string& id);

      static GetSpoofTxColorPtr create(const std::string& id);
      static GetSpoofTxColorPtr dynamicCast(CommandBasePtr ptr);
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

