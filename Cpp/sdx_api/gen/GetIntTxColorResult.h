#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxColor.
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------------------------------------------------------
    /// Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).
    /// Id    string Transmitter unique identifier.
    ///

    class GetIntTxColorResult;
    typedef std::shared_ptr<GetIntTxColorResult> GetIntTxColorResultPtr;
    
    
    class GetIntTxColorResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxColorResult();

      GetIntTxColorResult(const std::string& color, const std::string& id);

      GetIntTxColorResult(CommandBasePtr relatedCommand, const std::string& color, const std::string& id);

      static GetIntTxColorResultPtr create(const std::string& color, const std::string& id);

      static GetIntTxColorResultPtr create(CommandBasePtr relatedCommand, const std::string& color, const std::string& id);
      static GetIntTxColorResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** color ****
      std::string color() const;
      void setColor(const std::string& color);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxColorResult);
  }
}

