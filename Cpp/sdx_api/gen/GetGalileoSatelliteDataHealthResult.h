#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoSatelliteDataHealth
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..36
    /// Component string Component is either "E5a", "E5b", or "E1B"
    /// Health    bool   False means Navigation data valid; True means Working without guarantee
    ///

    class GetGalileoSatelliteDataHealthResult;
    typedef std::shared_ptr<GetGalileoSatelliteDataHealthResult> GetGalileoSatelliteDataHealthResultPtr;
    
    
    class GetGalileoSatelliteDataHealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoSatelliteDataHealthResult();

      GetGalileoSatelliteDataHealthResult(CommandBasePtr relatedCommand, int prn, const std::string& component, bool health);
  
      static GetGalileoSatelliteDataHealthResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& component, bool health);
      static GetGalileoSatelliteDataHealthResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

