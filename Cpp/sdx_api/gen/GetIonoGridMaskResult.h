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
    /// Result of GetIonoGridMask.
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------
    /// ServiceProvider string The service provider
    /// Band            int    The ionospheric grid band index
    /// Point           int    The IGP index
    /// Flag            bool   Is the IGP monitored
    ///

    class GetIonoGridMaskResult;
    typedef std::shared_ptr<GetIonoGridMaskResult> GetIonoGridMaskResultPtr;
    
    
    class GetIonoGridMaskResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoGridMaskResult();

      GetIonoGridMaskResult(const std::string& serviceProvider, int band, int point, bool flag);

      GetIonoGridMaskResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int band, int point, bool flag);

      static GetIonoGridMaskResultPtr create(const std::string& serviceProvider, int band, int point, bool flag);

      static GetIonoGridMaskResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int band, int point, bool flag);
      static GetIonoGridMaskResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);


      // **** flag ****
      bool flag() const;
      void setFlag(bool flag);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridMaskResult);
  }
}

