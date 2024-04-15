#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the flag for a ionospheric grid point in the SBAS message 18 mask
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------
    /// ServiceProvider string The service provider
    /// Band            int    The ionospheric grid band index
    /// Point           int    The IGP index
    ///

    class GetIonoGridMask;
    typedef std::shared_ptr<GetIonoGridMask> GetIonoGridMaskPtr;
    
    
    class GetIonoGridMask : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoGridMask();

      GetIonoGridMask(const std::string& serviceProvider, int band, int point);

      static GetIonoGridMaskPtr create(const std::string& serviceProvider, int band, int point);
      static GetIonoGridMaskPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);
    };
    
  }
}

