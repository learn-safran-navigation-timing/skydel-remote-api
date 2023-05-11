#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the flag for a ionospheric grid point in the SBAS message 18 mask
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------
    /// ServiceProvider string The service provider
    /// Band            int    The ionospheric grid band index
    /// Point           int    The IGP index
    /// Flag            bool   Is the IGP monitored
    ///

    class SetIonoGridMask;
    typedef std::shared_ptr<SetIonoGridMask> SetIonoGridMaskPtr;
    
    
    class SetIonoGridMask : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIonoGridMask();

      SetIonoGridMask(const std::string& serviceProvider, int band, int point, bool flag);

      static SetIonoGridMaskPtr create(const std::string& serviceProvider, int band, int point, bool flag);
      static SetIonoGridMaskPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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


      // **** flag ****
      bool flag() const;
      void setFlag(bool flag);
    };
    
  }
}

