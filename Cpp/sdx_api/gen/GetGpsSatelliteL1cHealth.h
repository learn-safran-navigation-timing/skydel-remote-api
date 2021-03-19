#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteL1cHealth is deprecated since 21.3. You may use GpsL1cHealthForSV.
    /// 
    /// Get GPS L1C health (used in CNAV2 only)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteL1cHealth;
    typedef std::shared_ptr<GetGpsSatelliteL1cHealth> GetGpsSatelliteL1cHealthPtr;
    
    
    class GetGpsSatelliteL1cHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL1cHealth();

      GetGpsSatelliteL1cHealth(int prn);
  
      static GetGpsSatelliteL1cHealthPtr create(int prn);
      static GetGpsSatelliteL1cHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

