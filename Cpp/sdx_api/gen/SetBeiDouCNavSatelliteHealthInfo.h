#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouCNavSatelliteHealthInfo is deprecated since 21.3. You may use BeiDouCNavHealthInfoForSV.
    /// 
    /// Set BeiDou CNav satellite health info
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health int  Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255
    ///

    class SetBeiDouCNavSatelliteHealthInfo;
    typedef std::shared_ptr<SetBeiDouCNavSatelliteHealthInfo> SetBeiDouCNavSatelliteHealthInfoPtr;
    
    
    class SetBeiDouCNavSatelliteHealthInfo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouCNavSatelliteHealthInfo();

      SetBeiDouCNavSatelliteHealthInfo(int prn, int health);
  
      static SetBeiDouCNavSatelliteHealthInfoPtr create(int prn, int health);
      static SetBeiDouCNavSatelliteHealthInfoPtr dynamicCast(CommandBasePtr ptr);
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

