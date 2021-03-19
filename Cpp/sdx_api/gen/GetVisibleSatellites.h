#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetVisibleSatellites is deprecated since 21.3. You may use GetVisibleSV.
    /// 
    /// Get a list of visible satellites within a system, returns a GetVisibleSatellitesResult
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------
    /// System string The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetVisibleSatellites;
    typedef std::shared_ptr<GetVisibleSatellites> GetVisibleSatellitesPtr;
    
    
    class GetVisibleSatellites : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVisibleSatellites();

      GetVisibleSatellites(const std::string& system);
  
      static GetVisibleSatellitesPtr create(const std::string& system);
      static GetVisibleSatellitesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

