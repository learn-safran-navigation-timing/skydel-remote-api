#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a satellite is geostationary
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId        int             The satellite SV ID
    /// IsGeo       bool            True for geostationary satellite
    /// Longitude   double          The longitude to use, in degree
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class ForceSVGeo;
    typedef std::shared_ptr<ForceSVGeo> ForceSVGeoPtr;
    
    
    class ForceSVGeo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ForceSVGeo();

      ForceSVGeo(const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName = {});

      static ForceSVGeoPtr create(const std::string& system, int svId, bool isGeo, double longitude, const Sdx::optional<std::string>& dataSetName = {});
      static ForceSVGeoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** isGeo ****
      bool isGeo() const;
      void setIsGeo(bool isGeo);


      // **** longitude ****
      double longitude() const;
      void setLongitude(double longitude);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

