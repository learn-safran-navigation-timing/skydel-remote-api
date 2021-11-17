#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSatelliteSignalHealth is deprecated since 21.3. You may use GetGpsSignalHealthForSV.
    /// 
    /// Get GPS signal health
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteSignalHealth;
    typedef std::shared_ptr<GetGpsSatelliteSignalHealth> GetGpsSatelliteSignalHealthPtr;
    
    
    class GetGpsSatelliteSignalHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteSignalHealth();

      GetGpsSatelliteSignalHealth(int prn);
  
      static GetGpsSatelliteSignalHealthPtr create(int prn);
      static GetGpsSatelliteSignalHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

