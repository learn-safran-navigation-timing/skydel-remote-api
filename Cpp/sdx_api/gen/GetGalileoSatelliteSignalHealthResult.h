#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoSatelliteSignalHealth.
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------
    /// Prn       int    Satellite PRN number 1..36
    /// Component string Component is either "E5a", "E5b", or "E1B"
    /// Health    int    Signal health 0..3
    ///

    class GetGalileoSatelliteSignalHealthResult;
    typedef std::shared_ptr<GetGalileoSatelliteSignalHealthResult> GetGalileoSatelliteSignalHealthResultPtr;
    
    
    class GetGalileoSatelliteSignalHealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoSatelliteSignalHealthResult();

      GetGalileoSatelliteSignalHealthResult(CommandBasePtr relatedCommand, int prn, const std::string& component, int health);
  
      static GetGalileoSatelliteSignalHealthResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& component, int health);
      static GetGalileoSatelliteSignalHealthResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

