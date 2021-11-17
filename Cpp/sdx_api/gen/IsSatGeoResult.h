#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSatGeo.
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------------------------------------------------------------------------------------------------
    /// System    string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Prn       int    The satellite to make geostationary. Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// IsGeo     bool   True for geostationary satellite
    /// Longitude double The longitude to use, in degree
    ///

    class IsSatGeoResult;
    typedef std::shared_ptr<IsSatGeoResult> IsSatGeoResultPtr;
    
    
    class IsSatGeoResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSatGeoResult();

      IsSatGeoResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool isGeo, double longitude);
  
      static IsSatGeoResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool isGeo, double longitude);
      static IsSatGeoResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** isGeo ****
      bool isGeo() const;
      void setIsGeo(bool isGeo);


      // **** longitude ****
      double longitude() const;
      void setLongitude(double longitude);
    };
  }
}

