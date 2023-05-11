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
    /// Get BeiDou CNav satellite health info
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouCNavHealthInfoForSV;
    typedef std::shared_ptr<GetBeiDouCNavHealthInfoForSV> GetBeiDouCNavHealthInfoForSVPtr;
    
    
    class GetBeiDouCNavHealthInfoForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNavHealthInfoForSV();

      GetBeiDouCNavHealthInfoForSV(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetBeiDouCNavHealthInfoForSVPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetBeiDouCNavHealthInfoForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

