#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSatelliteDataHealth is deprecated since 21.3. You may use GetGpsDataHealthForSV.
    /// 
    /// Get GPS nav data health
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteDataHealth;
    typedef std::shared_ptr<GetGpsSatelliteDataHealth> GetGpsSatelliteDataHealthPtr;
    
    
    class GetGpsSatelliteDataHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteDataHealth();

      GetGpsSatelliteDataHealth(int prn);
  
      static GetGpsSatelliteDataHealthPtr create(int prn);
      static GetGpsSatelliteDataHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

