#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoModel.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------------------------------------------
    /// Model string Ionospheric model ("None", "Klobuchar", "Spacecraft" or "NeQuick")
    ///

    class GetIonoModelResult;
    typedef std::shared_ptr<GetIonoModelResult> GetIonoModelResultPtr;
    
    
    class GetIonoModelResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoModelResult();

      GetIonoModelResult(const std::string& model);

      GetIonoModelResult(CommandBasePtr relatedCommand, const std::string& model);

      static GetIonoModelResultPtr create(const std::string& model);

      static GetIonoModelResultPtr create(CommandBasePtr relatedCommand, const std::string& model);
      static GetIonoModelResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** model ****
      std::string model() const;
      void setModel(const std::string& model);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIonoModelResult);
  }
}

