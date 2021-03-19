#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SatGeo is deprecated since 21.3. You may use ForceSVGeo.
    /// 
    /// Get whether a satellite is geostationary
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Prn    int    The satellite to make geostationary. Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class IsSatGeo;
    typedef std::shared_ptr<IsSatGeo> IsSatGeoPtr;
    
    
    class IsSatGeo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSatGeo();

      IsSatGeo(const std::string& system, int prn);
  
      static IsSatGeoPtr create(const std::string& system, int prn);
      static IsSatGeoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

