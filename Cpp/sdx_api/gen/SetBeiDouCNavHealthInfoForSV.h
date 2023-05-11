#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou CNav satellite health info
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// Health      int             Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetBeiDouCNavHealthInfoForSV;
    typedef std::shared_ptr<SetBeiDouCNavHealthInfoForSV> SetBeiDouCNavHealthInfoForSVPtr;
    
    
    class SetBeiDouCNavHealthInfoForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouCNavHealthInfoForSV();

      SetBeiDouCNavHealthInfoForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static SetBeiDouCNavHealthInfoForSVPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
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


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

