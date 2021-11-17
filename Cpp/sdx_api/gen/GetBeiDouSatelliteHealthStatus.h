#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouSatelliteHealthStatus is deprecated since 21.3. You may use GetBeiDouHealthStatusForSV.
    /// 
    /// Get BeiDou satellite health status
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouSatelliteHealthStatus;
    typedef std::shared_ptr<GetBeiDouSatelliteHealthStatus> GetBeiDouSatelliteHealthStatusPtr;
    
    
    class GetBeiDouSatelliteHealthStatus : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouSatelliteHealthStatus();

      GetBeiDouSatelliteHealthStatus(int prn);
  
      static GetBeiDouSatelliteHealthStatusPtr create(int prn);
      static GetBeiDouSatelliteHealthStatusPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

