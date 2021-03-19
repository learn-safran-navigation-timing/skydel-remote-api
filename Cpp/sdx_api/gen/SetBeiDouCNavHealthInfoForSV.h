#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou CNav satellite health info
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health int  Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255
    ///

    class SetBeiDouCNavHealthInfoForSV;
    typedef std::shared_ptr<SetBeiDouCNavHealthInfoForSV> SetBeiDouCNavHealthInfoForSVPtr;
    
    
    class SetBeiDouCNavHealthInfoForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouCNavHealthInfoForSV();

      SetBeiDouCNavHealthInfoForSV(int svId, int health);
  
      static SetBeiDouCNavHealthInfoForSVPtr create(int svId, int health);
      static SetBeiDouCNavHealthInfoForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

