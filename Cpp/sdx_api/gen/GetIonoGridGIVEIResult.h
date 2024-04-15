#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridGIVEI.
    ///
    /// Name            Type            Description
    /// --------------- --------------- -------------------------------
    /// Band            int             The ionospheric grid band index
    /// Point           int             The IGP index
    /// GiveI           int             The GIVEI at the IGP
    /// ServiceProvider optional string The service provider (optional)
    ///

    class GetIonoGridGIVEIResult;
    typedef std::shared_ptr<GetIonoGridGIVEIResult> GetIonoGridGIVEIResultPtr;
    
    
    class GetIonoGridGIVEIResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoGridGIVEIResult();

      GetIonoGridGIVEIResult(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider = {});

      GetIonoGridGIVEIResult(CommandBasePtr relatedCommand, int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider = {});

      static GetIonoGridGIVEIResultPtr create(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider = {});

      static GetIonoGridGIVEIResultPtr create(CommandBasePtr relatedCommand, int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider = {});
      static GetIonoGridGIVEIResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);


      // **** giveI ****
      int giveI() const;
      void setGiveI(int giveI);


      // **** serviceProvider ****
      Sdx::optional<std::string> serviceProvider() const;
      void setServiceProvider(const Sdx::optional<std::string>& serviceProvider);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridGIVEIResult);
  }
}

