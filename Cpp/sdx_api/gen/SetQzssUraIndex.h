#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssUraIndex is deprecated since 21.3. You may use SetQzssUraIndexForSV.
    /// 
    /// Set the URA index of a QZSS satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.
    /// Urai        int             URA index.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssUraIndex;
    typedef std::shared_ptr<SetQzssUraIndex> SetQzssUraIndexPtr;
    
    
    class SetQzssUraIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssUraIndex();

      SetQzssUraIndex(int svId, int urai, const std::optional<std::string>& dataSetName = {});

      static SetQzssUraIndexPtr create(int svId, int urai, const std::optional<std::string>& dataSetName = {});
      static SetQzssUraIndexPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** urai ****
      int urai() const;
      void setUrai(int urai);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

