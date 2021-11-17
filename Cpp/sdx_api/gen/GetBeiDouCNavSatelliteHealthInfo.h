#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouCNavSatelliteHealthInfo is deprecated since 21.3. You may use GetBeiDouCNavHealthInfoForSV.
    /// 
    /// Get BeiDou CNav satellite health info
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouCNavSatelliteHealthInfo;
    typedef std::shared_ptr<GetBeiDouCNavSatelliteHealthInfo> GetBeiDouCNavSatelliteHealthInfoPtr;
    
    
    class GetBeiDouCNavSatelliteHealthInfo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNavSatelliteHealthInfo();

      GetBeiDouCNavSatelliteHealthInfo(int prn);
  
      static GetBeiDouCNavSatelliteHealthInfoPtr create(int prn);
      static GetBeiDouCNavSatelliteHealthInfoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

