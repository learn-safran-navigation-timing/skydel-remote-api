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
    /// Add a new data set for the specified constellation. This could come from a Rinex, SEM or YUMA file for GPS. Only Rinex for the others.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// Path        string          Data set file path
    /// Rollover    optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.
    /// DataSetName optional string Name of the data set to import. This parameter is optional, the default value will be the name of the imported file.
    ///

    class AddDataSet;
    typedef std::shared_ptr<AddDataSet> AddDataSetPtr;
    
    
    class AddDataSet : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      AddDataSet();

      AddDataSet(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover = {}, const Sdx::optional<std::string>& dataSetName = {});

      static AddDataSetPtr create(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover = {}, const Sdx::optional<std::string>& dataSetName = {});
      static AddDataSetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** rollover ****
      Sdx::optional<int> rollover() const;
      void setRollover(const Sdx::optional<int>& rollover);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

