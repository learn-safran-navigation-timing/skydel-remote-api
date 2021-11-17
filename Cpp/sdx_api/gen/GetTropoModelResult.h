#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetTropoModel.
    ///
    /// Name  Type   Description
    /// ----- ------ -----------------------------------------------------------------
    /// Model string Tropospheric model ("None", "Saastamoinen", "Stanag" or "DO-229")
    ///

    class GetTropoModelResult;
    typedef std::shared_ptr<GetTropoModelResult> GetTropoModelResultPtr;
    
    
    class GetTropoModelResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetTropoModelResult();

      GetTropoModelResult(CommandBasePtr relatedCommand, const std::string& model);
  
      static GetTropoModelResultPtr create(CommandBasePtr relatedCommand, const std::string& model);
      static GetTropoModelResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** model ****
      std::string model() const;
      void setModel(const std::string& model);
    };
  }
}

