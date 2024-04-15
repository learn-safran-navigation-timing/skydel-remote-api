#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridError.
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------
    /// Band  int    The ionospheric grid band index
    /// Point int    The IGP index
    /// Error double The error offset at the IGP
    ///

    class GetIonoGridErrorResult;
    typedef std::shared_ptr<GetIonoGridErrorResult> GetIonoGridErrorResultPtr;
    
    
    class GetIonoGridErrorResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoGridErrorResult();

      GetIonoGridErrorResult(int band, int point, double error);

      GetIonoGridErrorResult(CommandBasePtr relatedCommand, int band, int point, double error);

      static GetIonoGridErrorResultPtr create(int band, int point, double error);

      static GetIonoGridErrorResultPtr create(CommandBasePtr relatedCommand, int band, int point, double error);
      static GetIonoGridErrorResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);


      // **** error ****
      double error() const;
      void setError(double error);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridErrorResult);
  }
}

