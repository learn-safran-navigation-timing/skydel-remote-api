#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouSatelliteHealthInfo is deprecated since 21.3. You may use BeiDouHealthInfoForSV.
    /// 
    /// Set BeiDou satellite health info
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health int  Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511
    ///

    class SetBeiDouSatelliteHealthInfo;
    typedef std::shared_ptr<SetBeiDouSatelliteHealthInfo> SetBeiDouSatelliteHealthInfoPtr;
    
    
    class SetBeiDouSatelliteHealthInfo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouSatelliteHealthInfo();

      SetBeiDouSatelliteHealthInfo(int prn, int health);
  
      static SetBeiDouSatelliteHealthInfoPtr create(int prn, int health);
      static SetBeiDouSatelliteHealthInfoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

