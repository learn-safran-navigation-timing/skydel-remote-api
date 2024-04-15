#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set a spoofer color in spectrums
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------------------------------------------------------
    /// Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).
    /// Id    string Transmitter unique identifier.
    ///

    class ChangeSpoofTxColor;
    typedef std::shared_ptr<ChangeSpoofTxColor> ChangeSpoofTxColorPtr;
    
    
    class ChangeSpoofTxColor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ChangeSpoofTxColor();

      ChangeSpoofTxColor(const std::string& color, const std::string& id);

      static ChangeSpoofTxColorPtr create(const std::string& color, const std::string& id);
      static ChangeSpoofTxColorPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** color ****
      std::string color() const;
      void setColor(const std::string& color);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

