#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Changes the custom signal color
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------------------------------------------------------
    /// Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).
    /// Id    string Custom signal ID
    ///

    class ChangeCustomSignalColor;
    typedef std::shared_ptr<ChangeCustomSignalColor> ChangeCustomSignalColorPtr;
    
    
    class ChangeCustomSignalColor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ChangeCustomSignalColor();

      ChangeCustomSignalColor(const std::string& color, const std::string& id);

      static ChangeCustomSignalColorPtr create(const std::string& color, const std::string& id);
      static ChangeCustomSignalColorPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

